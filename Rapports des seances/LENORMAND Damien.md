Ici, j'écrirais tous mes rapports de séances.

<h2>- Séance du 10 décembre :</h2>

- Tout d'abord, nous avons créé notre Github pour notre projet.

- Ensuite je me suis renseigné sur les differents modules dont nous auront besoin, tel que celui pour la température extérieure ainsi que la corporelle, le capteur de lumière et le capteur pour le rythme cardiaque.

- Pour la température exterieur nous allons utiliser un capteur LM35. Ce capteur nous permet de mesurer des températures pouvant aller de -40° à 85° qui est disponible <a href="https://www.conrad.fr/p/texas-instruments-lm-335-z-capteur-de-temperature-40-a-100-c-to-92-sortie-radiale-176656">ici</a>.

- Pour la température corporelle, le <a href="https://www.amazon.fr/MLX90614-Contact-Capteur-Temp%C3%A9rature-Infrarouge/dp/B0752D444T/ref=sr_1_7?ie=UTF8&qid=1544439196&sr=8-7&keywords=capteur%20ir%20arduino%20temperature&fbclid=IwAR0lnj9VVMJnB4Qq8FSv13xZcNp527qpPXtKi6elCzo3Gd2Q6tBUgipcS5Q">capteur de température infrarouge</a> peut être utiliser afin de mesurer la température qui se trouve proche de ce capteur.

- Pour le capteur de lumière, nous utiliserons une <a href="https://www.amazon.fr/Sodial-20x-Photor%C3%A9sistances-50-100-kOhms/dp/B00HUHC9D2/ref=sr_1_4?ie=UTF8&qid=1544439506&sr=8-4&keywords=photor%C3%A9sistance+arduino">photorésistance</a>. Cette photorésistance va renvoyer une certaine tension, si la tension atteint un seuil, plusieurs LED s'allumeront.

- Pour le rythme cardiaque, un capteur pulse sensor sera utilisé.

- Je me suis ensuite renseigner sur l'effet hall qui va permettre de mettre en place notre compteur de kilomètre ainsi que celui de vitesse. Cette effet est très bien expliquer <a href="http://etronics.free.fr/dossiers/analog/analog48/capthall.htm">ici</a>.

- Une fois la recherche des éléments terminée, nous avons essayé le module Sensor, pour le compteur de vitesse et kilomètre, afin de regarder ce que le module nous renvoie.
J'ai aussi commencé à chercher la formule pour convertir le nombre de tour par minute en km/h.

<h2>- Séance du 17 décembre :</h2>

- Dans un premier temps, j'ai modifié le programme du LOGO-sensor en y ajoutant les formule du nombre de kilomètre parcouru ainsi que celle de la vitesse(moyenne et instantanée). Pour l'insant l'aimant n'est toujours pas détecté. Le <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/LOGO-sensor%20avec%20distance%20et%20vitesse.ino">programme</a> est dans le dossier Code sur ce Github, il renvoie le nombre de kilomètre parcouru au total ainsi que la vitesse instantanée et la vitesse moyenne.

- Après branchement du capteur pulse sensor sur la carte Arduino, je me suis concentré sur le programme pour le capteur pulse sensor. A l'aide de plusieurs programme, j'ai finalement écrit un programme qui nous renvoie le battement seul. Ce programme nous renvoie bien le rythme cardiaque pour chaque battementsi la pulsation est assez forte poyr que le capteur la ressente. Le <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/Pulse%20sensor.ino">programme</a> est disponible dans le dossier Code sur le Github. 


<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Pulse%20sensor%20-%20Montage.png"/>


- Une fois que le module sensor nous a donné le rythme cardiaque nous sommes retourné sur le module LOGO-sensor qui, même apres avoir resouder ce module, ne détectait toujours pas de changement lorsqu'un aimant passe devant.


<h2>- Séance du 7 janvier :</h2>

- Suite au mail de Pascal Masson, j'ai modifié le programme pour le compteur de kilomètre et de distance. J'ai ajouté une interruption qui permet de rendre le programme juste en comptant le nombre de tour sur une certaine durée, que l'on utilise ensuite pour le convertir en km/h. Ce <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/LOGO-sensor%20avec%20interrruption.ino">programme</a> est disponible dans le dossier Code.

<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Capteur%20%C3%A0%20effet%20Hall%20-%20Montage.png"/>

- Je suis ensuite allé chercher le module logo sensor. Après avoir effectuer les branchements, j'ai testé le programme et une erreur intervient lors du calcul de la vitesse. Un autre problème est aussi présent, le capteur detecte plusieurs tour lorsque l'aimant passe dessus. Le calcul de la distance fonctionne et la vitesse moyenne aussi mais étant donné que la vitesse instantannée n'est pas la bonne, la valeur affichée est fausse.


<h2>- Séance du 14 janvier :</h2>

- La premiere chose que j'ai faite est d'écrire de nouveau le programme pour la vitesse, distance et vitesse moyenne. L'interruption du programme se fait au bon moment, grâce a l'utilisation du RISING. Mais lors de cette interruption ou seulement un seul tour doit être ajouter, des milliers de tour sont ajoutés sans raison. Lorsque que l'on passe l'aimant devant le capteur, et que le nombre de tour est afficher sur le moniteur série, des valeurs tel que 3500 apparaissent. 

- Le capteur détecte 3 états: 1 état LOW ou rien ne se passe et aucun tour est ajouter. Un état HIGH ou aucun tour n'est ajouter aussi. Et un état "entre 2" ou lorsque l'on reste sur cet état là, le nombre de tour ne fait qu'augmenter. C'est comme si un état RISING était détecté. Lors de cet état, le compteur augmente a l'infini. Le code est <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/LOGO-sensor%20avec%20interrruption.ino">ici</a>.

- À la suite de l'oral de 5min, j'ai commencé à me renseigner sur le module DHT11, celui qui va être utilisé pour la température extérieure ainsi que l'humidité.

<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/DHT11.png"/>


<h2>- Séance du 4 fevrier :</h2>

- J'ai commencé par effectuer le montage pour le module DHT11, module utilisé pour la température exterieur ainsi que l'humidité. Ce montage est fait a l'aide d'un condensateur. Une fois le montage effectuer, j'ai écrit le programme a l'aide d'un modèle trouver sur internet. le programme est <a href ="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/DHT11.ino">ici</a>.
Le module fonctionne correctement et nous affiche les valeurs de l'humidité et de la température.

<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Moniteur%20s%C3%A9rie%20des%20r%C3%A9sultats%20-%20DHT11.png"/>

- Je me suis ensuite renseigné sur le capteur pir qui nous a été fourni avec un capteur DT8260.
