#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const byte ROW_NUM = 4;
const byte COL_NUM = 4;
LiquidCrystal_I2C lcd(0x27,16, 2);
char keys[ROW_NUM][COL_NUM] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*','0','#','D'}  };
byte pin_rows[ROW_NUM] = {9, 8, 7, 6};
byte pin_column[COL_NUM] = {5, 4, 3, 2};
// This line creates an instance of the Keypad class called keypad to create the keymap for the keypad 
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COL_NUM );
void setup(){
  lcd.init();
  lcd.clear();
  lcd.backlight();
}
void loop(){
  char key = keypad.getKey();
  if (key){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Key Pressed: ");
    lcd.setCursor(0,1);
    lcd.print(key);
  }
}
