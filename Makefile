CPP=g++

ACT2SH = ./actividad-2-delimitadores/run.sh

delimiters: $(ACT2DIR)
	chmod +x $(ACT2SH)
	./$(ACT2SH)