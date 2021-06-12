/*
 * Обозначения и соответствующие номера портов
 * D1 5
 * D2 4
 * D3 0    Нельзя использовать при запуске
 * D4 2    Нельзя использовать при запуске (LED_BUILTIN)
 * D0 16   При использовании INPUT_PULLUP требуется дополнительный резистор от + к контакту-приёмнику esp
           При замыкании на +, esp не запускается в режиме прошивки
 * D5 14
 * D6 12
 * D7 13
 * D8 15   При использовании INPUT_PULLUP требуется допоолнительный резистор от + к контакту-приёмнику esp
 */
int buttons[] = {12, 13, 14, 4, 16};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < sizeof(buttons) / sizeof(int); i++)
    pinMode(buttons[i], INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  String test = "";
  for(int i = sizeof(buttons) / sizeof(int) - 3; i >= 0 ; i--)
    test.concat(!digitalRead(buttons[i]));
  for(int i = sizeof(buttons) / sizeof(int) - 2; i < sizeof(buttons) / sizeof(int); i++)
    test.concat(digitalRead(buttons[i]));
  Serial.println(test);
}
