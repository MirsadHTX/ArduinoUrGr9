# Pseudo kode for vores program

- Importere funktioner fra anden fil

- Setup
  - Start LCD skærm
  - Start accelorometer

- Loop
  - Hvis arduino bliver roteret til venstre, så skal state gå en ned
  - Hvis arduino bliver roteret til højre, så skal state gå en op

  - Check hvad state er lige nu
    - Hvis den er 0, så hvis ur
    - Hvis den er 1, så hvis stop-ur
    - Hvis den er 2, så hvis julekalender
    - Hvis den er 3, så hvis temperatur
    - Hvis den er 4, så hvis random-elev

  - Delay koden 50ms // fordi eller så kan skærmen ikke følge med
