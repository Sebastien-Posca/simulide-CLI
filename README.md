# simulide-CLI

* To start the simulation : <br />
`./simulide --simu pathToSimu --hex pathToHex` with the option `--platform offscreen` to start without display. <br />
The simulation logs are automatically saved in Json file when the program is closed with `CTRL+C`.

* To compare the logs of two executions: <br /> `./simulide --logs pathToLogs1 pathToLogs2 margin --platform offscreen`

* To replay a previous simulation, based on its logs: <br /> `./simulide --simu pathToSimu --play pathToLogs` 



* Pour lancer une simulation : <br />
`./simulide --simu pathToSimu --hex pathToHex` avec l'option `--platform offscreen` pour lancer sans écran. <br />
Les logs de la simulation sont sauvegardés automatiquement sous forme de fichier json quand le programme est fermé avec `CTRL+C`.

* Pour comparer les logs de deux exécutions : <br /> `./simulide --logs pathToLogs1 pathToLogs2 margin --platform offscreen`

* Pour rejouer une simulation antérieure en se basant sur les logs : <br /> `./simulide --simu pathToSimu --play pathToLogs` 
