
#platform dependent sources
ifeq ($(PLATFORM), HOST)
  SRCS = ./conversion.c \
         ./data.c       \
         ./debug.c      \
         ./endian.c     \
         ./main.c       \
         ./memory.c
else ifeq ($(PLATFORM), BBB)
  SRCS = ./conversion.c \
         ./data.c       \
         ./debug.c      \
         ./endian.c     \
         ./main.c       \
         ./memory.c 
else ifeq ($(PLATFORM), KL25Z)
  SRCS = ./conversion.c      \
         ./data.c            \
         ./debug.c           \
         ./endian.c          \
         ./main.c            \
         ./memory.c          \
         ./arch_arm32.c      \
         ./startup_MKL25Z4.S \
         ./system_MKL25Z4.c
endif
