
RM =	rm -rf
CP =	cp -rf
MV =	mv

ROOT_PATH =			./
COREWAR_PATH =		vm/
ASSEMBLER_PATH =	assembler/
ASSEMBLER =			asm
COREWAR =			corewar

all:
	@make all -s -C $(COREWAR_PATH)
	@$(MV) $(COREWAR_PATH)$(COREWAR) $(ROOT_PATH)$(COREWAR)
	@make all -s -C $(ASSEMBLER_PATH) $(ROOT_PATH)$(ASSEMBLER)
	@$(MV) $(ASSEMBLER_PATH)$(ASSEMBLER) $(ROOT_PATH)$(ASSEMBLER)

clean:
	@make clean -s -C $(COREWAR_PATH)
	@make clean -s -C $(ASSEMBLER_PATH)

fclean: clean
	@make fclean -s -C $(COREWAR_PATH)
	@$(RM) $(ROOT_PATH)$(COREWAR)
	@make fclean -s -C $(ASSEMBLER_PATH)
	@$(RM) $(ROOT_PATH)$(ASSEMBLER)

re: fclean all

.PHONY: all clean fclean re
