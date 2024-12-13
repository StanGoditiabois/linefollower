# Instructable

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

### stap 1
Bestel alle componenten uit de bill of materials  

### Stap 2: Chassis Montage
Soldeer de female header pinns voor de ESP32 op de onderkant van de printplaat.
Soldeer de male header pins aan QTR8-A en DRV-8833.
Soldeer de female header pins voor de QTR8-A en DRV-8833 aan de printplaat.
Soldeer de drukknoppen, condensatoren, weerstanden, en Voltregulator op de printplaat alvorens je de batterijhouder erop soldeert.
Soldeer de batterijhouder op het chassis.
Bevestig de motoren op het chassis met schroeven door middel van een 3D-print houder.
Soldeer aan de motoren dupont draadjes
Monteer de wielen op de motorassen.
Monteer de lijnvolgsensoren aan de voorkant van het chassis en plak het oogje achter de sensoren zodat deze niet op het papier hangen.
Bevestig de motor driver module en ESP32 module op het chassis .

### Stap 3: Elektrische Verbindingen
Motor driver module:
Verbind de Dupont draadjes met de female header pinns gesoldeerd op J1-MotorL en J2-MotorR.

Lijnvolgsensoren:
Maak een loop op de 3.3V bypass 

### Stap 4: Software Installatie
ESP32 configureren in Arduino IDE:
Open de Arduino IDE.
Ga naar Tools > Board > Board Manager en installeer de ESP32-bibliotheek.

Bibliotheken installeren:
Installeer de benodigde bibliotheken:
SerialCommand (Steven Cogswell.

Code uploaden:
Sluit de ESP32 aan op de computer via een USB-kabel.
Selecteer de juiste boardinstellingen:
Board: ESP32 Dev Module
Port: (selecteer de juiste COM-poort)
Upload de code

Bluetooth testen:
Verbind met de ESP32 via Bluetooth vanaf een smartphone of computer.
Test de communicatie door gegevens te verzenden en te ontvangen.

### Stap 5: Functionele Test
Sluit de batterij aan op de batterijhouders.
Plaats de robot op het zwarte vlak en calibreer, plaat de robot op Wit en calibreer.
Plaats de robot op een zwart-witte lijn.
Controleer of de robot de lijn correct volgt.

### Stap 6: Fijnafstelling en Optimalisatie
Optimaliseer de snelheid door de PWM-signalen voor de motoren te implementeren.
Verbeter de lijnvolging door gebruik te maken van PID-regeling in de code.
Voeg Bluetooth-functionaliteit toe om parameters zoals snelheid en gevoeligheid in real-time aan te passen.


Je linefollower robot is nu klaar!
