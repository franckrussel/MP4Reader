.PHONY: clean All

All:
	@echo "----------Building project:[ IsoReader - Release ]----------"
	@cd "IsoReader" && "$(MAKE)" -f  "IsoReader.mk"
clean:
	@echo "----------Cleaning project:[ IsoReader - Release ]----------"
	@cd "IsoReader" && "$(MAKE)" -f  "IsoReader.mk" clean
