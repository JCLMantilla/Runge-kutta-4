plot.png : friction.dat frictionless.dat
	python plotdata.py
	
friction.dat frictionless.dat : friction.x frictionless.x
	./friction.x > friction.dat
	./frictionless.x > frictionless.dat

friction.x frictionless.x : friction.cpp frictionless.cpp
	c++ friction.cpp -o friction.x
	c++ frictionless.cpp -o frictionless.x




