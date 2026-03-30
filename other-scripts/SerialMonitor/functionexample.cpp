#include <Arduino.h>

void greetUser() {
  Serial.println("Hello!");
}

void sayHello(String userName) {
  Serial.print("Hello, ");
  Serial.print(userName);
  Serial.println("!");
}

void describePet (String animalType, String petName) {
  Serial.print("I have a ");
  Serial.print(animalType);
  Serial.print(" named ");
  Serial.println(petName);
}

void describePC(String brand, String model, int ram, int storage, String cpu = "unknown") {
  // default parameters must be placed at the end
  Serial.print("I have a ");
  Serial.print(brand);
  Serial.print(" ");
  Serial.print(model);
  Serial.print(" with ");
  Serial.print(ram);
  Serial.print("GB RAM, ");
  Serial.print(storage);
  Serial.print("GB storage, and a ");
  Serial.print(cpu);
  Serial.println(" CPU.");
}

String getFormattedName (String firstName, String lastName) {
  String fullName = firstName + " " + lastName;
  return fullName;
}

int addNumbers(int num1, int num2) {
  return num1 + num2;
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n");

  greetUser();
  sayHello("Noah");
  describePet("Cat", "Felix");
  // describePet("Ralph", "Cat"); // Incorrect example
  describePC("Dell", "XPS 15", 16, 512, "Intel Core i7");
  
  String formattedName = getFormattedName("Noah", "?");
  Serial.println(formattedName);

  int sum = addNumbers(5, 7);
  Serial.print("The sum of 5 and 7 is: ");
  Serial.println(sum);
}

void loop() {
  // empty
}