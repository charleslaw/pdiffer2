
all: CompareArgs.so Metric.so

CompareArgs.so:
	g++ -fPIC -shared RGBAImage_np.cpp CompareArgs.cpp -o CompareArgs.so

Metric.so:
	g++ -fPIC -shared RGBAImage_np.cpp LPyramid.cpp CompareArgs.cpp Metric.cpp -o Metric.so

clean:
	rm -f CompareArgs.so
	rm -f Metric.so
