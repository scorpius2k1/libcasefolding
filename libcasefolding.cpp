#include <cctype>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <dlfcn.h>
#include <link.h>

extern "C" char* strncpy(char* dst, const char* src, size_t dsize) {
	static auto* orig = (decltype(strncpy)*)dlsym(RTLD_NEXT, "strncpy");
	static void* base = nullptr;

  if (base == nullptr) {
		void* handle = dlopen("filesystem_stdio.so", RTLD_NOW | RTLD_NOLOAD);
		if (!handle)
			return orig(dst, src, dsize);
		link_map* map;
		if (dlinfo(handle, RTLD_DI_LINKMAP, &map) == -1) {
			printf("%s\n", dlerror());
			return orig(dst, src, dsize);
		}
		base = (void*)map->l_addr;
		printf("Found base at %p\n", base);
	}

	if (base) {
		void* retaddr = __builtin_extract_return_addr(__builtin_return_address(0));
		if ((uintptr_t)base + 0xcfa62 == (uintptr_t)retaddr) {
			void* retaddr = __builtin_extract_return_addr(__builtin_return_address(1));
			if ((uintptr_t)base + 0xdfe56 == (uintptr_t)retaddr || (uintptr_t)base + 0xe028e == (uintptr_t)retaddr) {
				char* rv = orig(dst, src, dsize);
				char* x = rv;
				while (x && *x) {
					*x = tolower(*x);
					x++;
				}
				return rv;
			}
		}
	}

	return orig(dst, src, dsize);
}
