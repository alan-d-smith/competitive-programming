LATEXCMD = pdflatex -shell-escape -output-directory build/
ifeq ($(OS),Windows_NT)
export TEXINPUTS=.;content/tex/;
else
export TEXINPUTS=.:content/tex/:
endif
export max_print_line = 1048576

help:
	@echo "This makefile builds the team reference document (TRD)"
	@echo ""
	@echo "Available commands are:"
	@echo "	make fast		- to build the TRD, quickly (only runs LaTeX once)"
	@echo "	make trd		- to build the TRD"
	@echo "	make label		- to build the binder label"
	@echo "	make clean		- to clean up the build process"
	@echo "	make veryclean		- to clean up and remove trd.pdf and label.pdf"
	@echo "	make help		- to show this information"
	@echo "	make showexcluded	- to show files that are not included in the doc"

fast: | build
	$(LATEXCMD) content/trd.tex </dev/null
	cp build/trd.pdf trd.pdf

trd: | build
	$(LATEXCMD) content/trd.tex && $(LATEXCMD) content/trd.tex
	cp build/trd.pdf trd.pdf

label: | build
	pdflatex -output-directory build/ content/label.tex </dev/null
	cp build/label.pdf label.pdf

clean:
	cd build && rm -f trd.aux trd.log trd.tmp trd.toc trd.pdf trd.ptc label.aux label.log label.pdf

veryclean: clean
	rm -f trd.pdf label.pdf

.PHONY: help fast trd label clean veryclean showexcluded

build:
	mkdir -p build/

showexcluded: build
	grep -RoPh '^\s*\kactlimport{\K.*' content/ | sed 's/.$$//' > build/headers_included
	find ./content -name "*.h" -o -name "*.py" -o -name "*.java" | grep -vFf build/headers_included
