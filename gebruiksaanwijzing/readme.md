# Gebruiksaanwijzing

### opladen / vervangen batterijen
Bij deze robot worden 18650 batterijen gebruikt deze kunnen worden opgeladen met een lader die hiervoor is gemaakt.

### draadloze communicatie
#### verbinding maken
Zet de bluetooth van je gsm aan en verbind met de auto. Open de bluetooth serial terminal app en verbind nu via deze app met de auto. Je kan nu via het tekstvak commando's versturen naar de auto.

#### commando's
debug / geeft een lijst van ingestelde parameters 
run aan / zorgt ervoor dat de auto begint te rijden  
run uit / zorgt ervoor dat de auto stopt met rijden
set cycle [µs] / bepaald de cyclustijd. deze moet altijd 1.5 tot 2x groter zijn dan de calculation time
set power [0..255] / bepaalt de snelheid van de auto
set diff [0..1] / bepaald of de auto versneld (> 0.5) of vertraagd (< 0.5) in de bochten.
set kp [0..] / bepaald de kp waarde van de pid regelaar
set ki [0..] / bepaald de ki waarde van de pid regelaar
set kd [0..] / bepaald de kd waarde van de pid regelaar
calibrate black / de sensoren worden gekalibreerd op de zwartwaarden
calibrate white / de sensoren worden gekalibreerd op de witwaarden

### kalibratie
Om te kalibreren plaats je eerst de robot met elke sensor over een zwart stuk. stuur het commando "calibrate black". Plaats dan de auto met elke sensor over een wit stuk en stuur nu het commando "calibrate white". De sensoren zijn nu gekalibreerd.

### settings
De robot rijdt stabiel met volgende parameters: 
power: 200
diff: 0.4
kp: 18
ki: 0
kd: 0.2

### start/stop button
De twee knoppen zijn te vinden tussen de batterijen. Knop 22 wordt gebruikt om de robot te laten stoppen en knop 23 om de robot te laten starten.
