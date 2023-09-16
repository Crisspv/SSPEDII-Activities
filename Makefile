CPP=g++

BINDIR = bin
ACT2DIR = ./actividad-2-delimitadores
ACT3DIR = ./actividad-3-campos-de-dimension

act2: $(ACT2DIR)
	cd $(ACT2DIR) && \
		rm -rf $(BINDIR) && \
		mkdir $(BINDIR) && \
		$(CPP) -o $(BINDIR)/act2 main.cpp menu.cpp calculator.cpp file.cpp && \
		$(BINDIR)/act2

act3: $(ACT3DIR)
	cd $(ACT3DIR) && \
		rm -rf $(BINDIR) && \
		mkdir $(BINDIR) && \
		$(CPP) -o $(BINDIR)/act3 main.cpp menu.cpp student.cpp file.cpp && \
		$(BINDIR)/act3
