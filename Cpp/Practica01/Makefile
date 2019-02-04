#Definicion de variables
Proyecto=Ejecutable
Compilador=g++

#Comandos para el archivo Make
all:$(Proyecto)

%.o:%.cpp
	$(Compilador) -c $<

$(Proyecto):Main.o Archivo.o Menu.o AritmeticaModular.o Cifrado.o Euclides.o
	$(Compilador) $^ -o $(Proyecto)
#Objetivos falsos
clean:
	rm *.o $(Proyecto)
