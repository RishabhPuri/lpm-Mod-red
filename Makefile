ifndef RM_INCLUDE_DIR
	RM_INCLUDE_DIR=../RedisModulesSDK/
endif

ifndef RM_UTIL_LIB_DIR
	RM_UTIL_LIB_DIR=../RedisModulesSDK/rmutil/
endif

SHOBJ_CFLAGS ?=  -fno-common -g -ggdb
SHOBJ_LDFLAGS ?= -shared


CFLAGS =  -I$(RM_INCLUDE_DIR) -g -fPIC -std=gnu99
CC=gcc
.SUFFIXES: .c .so .o

MODULE = lpmMod

all: $(MODULE)

$(MODULE): %: %.o
	$(LD) -o $@.so $< $(SHOBJ_LDFLAGS) $(LIBS) -L$(RM_UTIL_LIB_DIR) -lrmutil 

.PHONY: clean
clean:
	rm -rf *.so *.o

    
       
