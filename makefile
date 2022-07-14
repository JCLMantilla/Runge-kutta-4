ejercicio28.png : ejercicio28.dat ejercicio28_sin_friccion.dat
	python ejercicio28.py
	
ejercicio28.dat ejercicio28_sin_friccion.dat : ejercicio28.x ejercicio28_sin_friccion.x
	./ejercicio28.x > ejercicio28.dat
	./ejercicio28_sin_friccion.x > ejercicio28_sin_friccion.dat

ejercicio28.x ejercicio28_sin_friccion.x : ejercicio28.cpp ejercicio28_sin_friccion.cpp
	c++ ejercicio28.cpp -o ejercicio28.x
	c++ ejercicio28_sin_friccion.cpp -o ejercicio28_sin_friccion.x




