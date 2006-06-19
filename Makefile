# Makefile for pimpmobile module player

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPro")
endif

DEVKITARM = $(DEVKITPRO)/devkitARM
LIBGBA    = $(DEVKITPRO)/libgba

PREFIX ?= arm-eabi-
CC      = $(PREFIX)gcc
CXX     = $(PREFIX)g++
OBJCOPY = $(PREFIX)objcopy
STRIP   = $(PREFIX)strip
LD      = $(PREFIX)g++
AS      = $(PREFIX)as
AR      = $(PREFIX)ar

CPPFLAGS = -I$(DEVKITARM)/include -I$(LIBGBA)/include
CFLAGS   = -mthumb-interwork -mlong-calls
CXXFLAGS = -mthumb-interwork -mlong-calls -fconserve-space -fno-rtti -fno-exceptions
LDFLAGS  = -mthumb-interwork -Wl,--gc-section -Wl,-Map,$(basename $@).map
ASFLAGS  = -mthumb-interwork

ARM   = -marm
THUMB = -mthumb

# TODO: profile what code to put where
OBJS = \
	src/pimp_gba.o         \
	src/pimp_render.o      \
	src/pimp_debug.o       \
	src/pimp_mod_context.o \
	src/pimp_math.iwram.o  \
	src/pimp_mixer.iwram.o

ifeq ($(DEBUG), 1)
	CPPFLAGS += -DDEBUG
	CXXFLAGS += -g3 -ggdb
	CFLAGS   += -g3 -ggdb
	OBJS     += src/mixer_portable.o
else
	CPPFLAGS += -DRELEASE -DNDEBUG
	CXXFLAGS += -O3 -fomit-frame-pointer
	CFLAGS   += -O3 -fomit-frame-pointer
	OBJS     += src/mixer_arm.iwram.o
#	OBJS     += src/mixer_portable.iwram.o
endif

	
.PHONY: all clean run debug

all: bin/example.gba

bin/example.gba: lib/libpimpmobile.a
	make -C example

clean:
	$(RM) bin/* $(OBJS) $(OBJS:.o=.d) lib/libpimpmobile.a *~ src/*~ include/*~
	make -C converter clean
	make -C example clean

run:
	make -C example run

debug:
	make -C example debug

bin/converter:
	make -C converter

bin/lut_gen: lut_gen.cpp src/math.cpp src/config.h
	g++ lut_gen.cpp src/math.cpp -o bin/lut_gen

lib/libpimpmobile.a: $(OBJS)

%.a:
	$(AR) $(ARFLAGS) $@ $?

%.iwram.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ARM) -c $< -o $@ -MMD -MF $(@:.o=.d)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(THUMB) -c $< -o $@ -MMD -MF $(@:.o=.d)

%.iwram.s: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -S -fverbose-asm $(ARM) -c $< -o $@

%.s: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -S -fverbose-asm $(THUMB) -c $< -o $@

-include $(OBJS:.o=.d)
