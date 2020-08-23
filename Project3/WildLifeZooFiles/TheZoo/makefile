# this file generates a .h file with JNI stubs
header:
	mkdir -p jni
	javac -h jni src/TheZoo/ZooFileWriter.java
	rm src/TheZoo/ZooFileWriter.java

# this generates a aignature, asking the user fir a class name; it then
# prints the field and method signatures for that class

sig:
	@bash -c 'read -p "Fully-qualified class name (example: java.util.List) ? " CLASSNAME && javap -s $$CLASSNAME';
	
# this makes signatures to print the field and method of the ZooFileWriter class
signatures: 
	javac src/TheZoo/ZooFileWriter.java -d bin
	javap -s -p bin/src/TheZoo/ZooFileWriter.java