# Forward all targets to the Makefile in src/ so "make <target>" works from repo root.
.DEFAULT_GOAL := __forward

.PHONY: __forward
__forward:
	@$(MAKE) -f src/Makefile $(MAKECMDGOALS)

ifneq ($(strip $(MAKECMDGOALS)),)
.PHONY: $(MAKECMDGOALS)
$(MAKECMDGOALS): __forward
	@:
endif
