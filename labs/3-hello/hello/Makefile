# change this name to whatever your program is called
NAME=hello
# add any additional .o's here
OBJS = $(NAME).o

# check that your path is defined.
ifndef CS49N_2020_LIBPI_PATH
$(error CS49N_2020_LIBPI_PATH is not set: this should contain the absolute path to where this directory is.  Define it in your shell's initialiation.  For example, .tcshrc for tcsh or .bashrc for bash)
endif

# useful set of defines.
include $(CS49N_2020_LIBPI_PATH)/includes.mk

START = $(LPI_PATH)/cs49n-start.o
MEMMAP = $(LPI_PATH)/memmap

CFLAGS += -Wstack-usage=512 -Wno-unused-function -Wno-unused-variable
CFLAGS += -Werror

all: libpi $(NAME).bin 

# is there a better way to do this?
libpi:
	@make -C $(LPI_PATH)

$(NAME).bin: $(START) $(MEMMAP) $(OBJS)
	$(LD) $(START) $(OBJS) -T $(MEMMAP) -o $(NAME).elf  $(LPI)
	$(OD) -D $(NAME).elf > $(NAME).list
	$(OCP) $(NAME).elf -O binary $(NAME).bin

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

# should re-do this to use the libpi makefile.

# http://scottmcpeak.com/autodepend/autodepend.html
# compile and generate dependency info;
# more complicated dependency computation, so all prereqs listed
# will also become command-less, prereq-less targets
#   sed:    strip the target (everything before colon)
#   sed:    remove any continuation backslashes
#   fmt -1: list words one per line
#   sed:    strip leading spaces
#   sed:    add trailing colons
%.o: %.c  Makefile
	$(CC) -c $(CFLAGS) $*.c -o $*.o
	$(CC) -MM $(CFLAGS) $*.c > $*.d
	@mv -f $*.d $*.d.tmp
	@sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp

.s.o: Makefile
	$(AS) $(ASFLAGS) $< -o $@

.S.o: Makefile
	$(CC) -c $(CPP_ASFLAGS) $< -o $@

run:
	my-install $(NAME).bin

tags:
	@rm -f tags
	ctags *.[chsS] $(LPI_PATH)/*.[chsS]

# remove compilation products
clean:
	rm -f replay *.o *.d *.bin *.elf *.list *.img Makefile.bak *~ tags

.PHONY: run libpi tags clean
