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

