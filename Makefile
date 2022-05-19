# Generated with GenMake
# Arthur-TRT - https://github.com/arthur-trt/genMake
# genmake v1.1.1

#Compiler and Linker
CC					:= clang
CXX					:= c++
ifeq ($(shell uname -s),Darwin)
	CC				:= gcc
	CXX				:= g++
endif

#The Target Binary Program
TARGET				:= ircserv
TARGET_BONUS		:= ircserv-bonus

BUILD				:= release

include sources.mk

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR				:= srcs
INCDIR				:= includes
BUILDDIR			:= obj
TARGETDIR			:= .
SRCEXT				:= cpp
DEPEXT				:= d
OBJEXT				:= o

OBJECTS				:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
OBJECTS_BONUS		:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES_BONUS:.$(SRCEXT)=.$(OBJEXT)))

#Flags, Libraries and Includes
cflags.release		:= -Wall -Werror -Wextra
cflags.valgrind		:= -Wall -Werror -Wextra -DDEBUG -ggdb
cflags.debug		:= -Wall -Werror -Wextra -DDEBUG -ggdb -fsanitize=address -fno-omit-frame-pointer
CFLAGS				:= $(cflags.$(BUILD))
CPPFLAGS			:= $(cflags.$(BUILD)) -std=c++98

lib.release			:= 
lib.valgrind		:= $(lib.release)
lib.debug			:= $(lib.release) -fsanitize=address -fno-omit-frame-pointer
LIB					:= $(lib.$(BUILD))

INC					:= -I$(INCDIR) -I/usr/local/include
INCDEP				:= -I$(INCDIR)

# Colors
C_RESET				:= \033[0m
C_PENDING			:= \033[0;36m
C_SUCCESS			:= \033[0;32m

# Multi platforms
ECHO				:= echo

# Escape sequences (ANSI/VT100)
ES_ERASE			:= "\033[1A\033[2K\033[1A"
ERASE				:= $(ECHO) $(ES_ERASE)

GREP				:= grep --color=auto --exclude-dir=.git
NORMINETTE			:= norminette `ls`

# Default Make
all: $(TARGETDIR)/$(TARGET)
	@$(ERASE)
	@$(ECHO) "$(TARGET)\t\t[$(C_SUCCESS)✅$(C_RESET)]"
	@$(ECHO) "$(C_SUCCESS)All done, compilation successful! 👌 $(C_RESET)"

# Bonus rule
bonus: CFLAGS += -DBONUS
bonus: CPPFLAGS += -DBONUS
bonus: $(TARGETDIR)/$(TARGET_BONUS)
	@$(ERASE)
	@$(ECHO) "$(TARGET)\t\t[$(C_SUCCESS)✅$(C_RESET)]"
	@$(ECHO) "$(C_SUCCESS)All done, compilation successful with bonus! 👌 $(C_RESET)"

# Remake
re: fclean all

# Clean only Objects
clean:
	@$(RM) -f *.d *.o
	@$(RM) -rf $(BUILDDIR)


# Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(TARGET)


# Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

# Link
$(TARGETDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CXX) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

# Link Bonus
$(TARGETDIR)/$(TARGET_BONUS): $(OBJECTS_BONUS)
	@mkdir -p $(TARGETDIR)
	$(CXX) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

$(BUILDIR):
	@mkdir -p $@

# Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(ECHO) "$(TARGET)\t\t[$(C_PENDING)⏳$(C_RESET)]"
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(INC) -c -o $@ $<
	@$(CXX) $(CFLAGS) $(CPPFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@$(ERASE)
	@$(ERASE)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp



norm:
	@$(NORMINETTE) | $(GREP) -v "Not a valid file" | $(GREP) "Error\|Warning" -B 1 || true

# Non-File Targets
.PHONY: all re clean fclean norm bonus
