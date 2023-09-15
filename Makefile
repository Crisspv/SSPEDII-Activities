CPP=g++

ACT2SH = ./actividad-2-delimitadores/run.sh
ACT3SH = ./actividad-3-campos-de-dimension/run.sh


delimiters: $(ACT2SH)
	chmod +x $(ACT2SH)
	./$(ACT2SH)

dimension-fields: $(ACT3SH)
	chmod +x $(ACT3SH)
	./$(ACT3SH)
