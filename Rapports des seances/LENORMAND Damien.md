Ici, j'écrirais tous mes rapports de séances.

<h2>- Séance du 10 décembre :</h2>

Tout d'abord, nous avons créés notre Github pour notre projet.

Ensuite je me suis renseigné sur les differents modules dont nous auront besoin, tel que celui pour la température exterieure ainsi que la corporelle, le capteur de lumière et le capteur pour le rythme cardiaque.

-Pour la température exterieur nous allons utiliser un capteur LM35. Ce capteur nous permet de mesurer des températures pouvat aller de -40° à 85° qui est disponible <a href="https://www.conrad.fr/p/texas-instruments-lm-335-z-capteur-de-temperature-40-a-100-c-to-92-sortie-radiale-176656">ici</a>.

-Pour la température corporelle, le <a href="https://www.amazon.fr/MLX90614-Contact-Capteur-Temp%C3%A9rature-Infrarouge/dp/B0752D444T/ref=sr_1_7?ie=UTF8&qid=1544439196&sr=8-7&keywords=capteur%20ir%20arduino%20temperature&fbclid=IwAR0lnj9VVMJnB4Qq8FSv13xZcNp527qpPXtKi6elCzo3Gd2Q6tBUgipcS5Q">capteur de température infrarouge</a> peut être utiliser afin de mesurer la température qui se trouve proche du ce capteur.

-Pour le capteur de lumière, nous utiliserons <a href="https://www.amazon.fr/Sodial-20x-Photor%C3%A9sistances-50-100-kOhms/dp/B00HUHC9D2/ref=sr_1_4?ie=UTF8&qid=1544439506&sr=8-4&keywords=photor%C3%A9sistance+arduino">une photorésistance</a>. Cette photorésistance va renvoyer une certaine tension, si la tension atteint un seuil, plusieurs LED s'allumeront.

-Pour le rythme cardiaque, un capteur pulse sensor sera utilisé.

Je me suis ensuite renseigner sur l'effet hall qui va permettre de mettre en place notre compteur de kilomètre ainsi que celui de vitesse. Cette effet est très bien expliquer <a href="http://etronics.free.fr/dossiers/analog/analog48/capthall.htm"> ici</a>.

Une fois la recherche des éléments terminée, nous avons essayé le module Sensor, pour le compteur de vitesse et kilomètre, afin de regarder ce que le module nous renvoie.
J'ai aussi commencé à chercher la formule pour convertir le nombre de tour par minute en km/h.

<h2>- Séance du 17 décembre :</h2>

-Dans un premier temps, j'ai modifié le programme du LOGO-sensor en y ajoutant les formule du nombre de kilomètre parcouru ainsi que celle de la vitesse(moyenne et instantanée). Pour l'insant l'aimant n'est toujours pas détecté. Le <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/Logo-sensor%20%2B%20distance%20et%20vitesse.ino">programme</a> est dans le dossier Code sur ce Github, il renvoie le nombre de kilomètre parcouru au total ainsi que la vitesse instantanée et la vitesse moyenne.

-Après branchement du capteur pulse sensor sur la carte Arduino, je me suis concentré sur le programme pour le capteur pouls sensor. A l'aide de plusieurs programme, j'ai finalement écrit un programme qui nous renvoie le battement seul. Ce programme nous renvoie bien le rythme cardiaque pour chaque battementsi la pulsation est assez forte poyr que le capteur la ressente. Le <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/Pulse%20sensor.ino">programme</a> est disponible dans le dossier Code sur le Github. 


<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Pulse%20sensor%20-%20Montage.png"/>


Une fois que le module sensor nous a donné le rythme cardiaque nous sommes retourné sur le module logo sensor qui, même apres avoir resouder ce module, ne detectait toujours pas de changement lorsqu'un aimant passe devant.


<h2>- Séance du 7 janvier :</h2>
