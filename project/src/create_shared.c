/*
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

void* create_shared_memory(size_t size) {
  // Our memory buffer will be readable and writable:
  int protection = PROT_READ | PROT_WRITE;

  // The buffer will be shared (meaning other processes can access it), but
  // anonymous (meaning third-party processes cannot obtain an address for it),
  // so only this process and its children will be able to use it:
  int visibility = MAP_SHARED | MAP_ANONYMOUS;

  // The remaining parameters to `mmap()` are not important for this use case,
  // but the manpage for `mmap` explains their purpose.
  return mmap(NULL, size, protection, visibility, -1, 0);
}


size_t page_size = getpagesize();

    char *shared_memory = mmap(NULL, page_size, PROT_READ | PROT_WRITE,
                               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    if (!shared_memory) {
        printf("Failed to map\n");
        return 1;
    }

    int v = 0;
    *shared_memory = 0;

    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork failed\n");
        if (munmap(shared_memory, page_size)) {
            printf("Failed to unmap\n");
        }
        return 1;
    }

    if (pid == 0) {
        *shared_memory = 42;
        v = 50;
    } else {
        pid_t wait_result = wait(NULL);
        if (wait_result != pid) {
            printf("Wait failed with code %d\n", wait_result);
        }
    }

    if (pid == 0) {
        printf("CHILD: Shared %d, not shared %d\n", *shared_memory, v);
    } else {
        printf("PARENT: Shared %d, not shared %d\n", *shared_memory, v);
    }

    if (pid) {
        if (munmap(shared_memory, page_size)) {
            printf("Failed to unmap\n");
        }
    }
*/
