<h1>Ici, j'écrirais tous mes rapports de séances.</h1>

<hr>
    
<h2>• Rapport de la séance 1 du Lundi 10 Décembre 2018 :</h2>

• Nous avons commencé par la création du GitHub pour le projet Arduino.

• Après avoir regardé les différents sites et nos besoins, j'ai conclu que le coût projet s'élèverait au maximum à 50€. Un prix plus juste est développé dans le <strong><a href="https://github.com/PolyTool/PolyTool/blob/master/Cahier%20des%20charges.md">cahier des charges</a></strong>.

• Nous avons également réfléchi quant à la répartition des tâches pour les différents modules et j'ai commencé à réaliser le <strong>diagramme de Gantt</strong>. J'essaierai de le finaliser avant la prochaine séance, c'est-à-dire avant le <strong>lundi 17 décembre 2018</strong>.

• J'ai commencé à écrire le <strong>cahier des charges</strong> afin que nous ayons une idée plus précise des choses à faire.

• Nous nous sommes ensuite renseignés quant aux différents modules à utiliser. Je me suis occupé de trouver quelques modules, comme le <em><a href="https://www.amazon.fr/Capteur-pouls-capteur-cardiaque-Arduino/dp/B01DKET4LS">capteur de pouls<a></em>.

• Pour le <em>compteur kilométrique</em> et le <em>compteur de vitesse</em>, je pense que nous avons besoin d'un unique module, qui fera les deux options en même temps en travaillant sur le code Arduino directement. Après avoir demandé de explications à M. Pascal Masson sur le fonctionnement de l'<strong>effet Hall</strong>, il m'a donné un module permettant de faire le <em>compteur kilométrique</em> (et je l'espère le <em>compteur de vitesse</em>, par le biais de ce module. Les informations concernant ce module se trouve <a href="http://lien-du-TD4-d-elec3-de-pmasson">ici</a>. De ce que j'ai retenu, il faudra détecter un changement de tension, lors du passage de l'aimant devant le module <strong>LOGO-sensor Ver1.3</strong>.

• J'ai alors testé le module <strong>LOGO-sensor Ver1.3</strong>, dont le code est disponible <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/LOGO-sensor%20Ver1.3.ino">ici</a>, mais un problème persiste. Il ne semble pas faire le distintion entre la présence d'aimant ou non.
<br>
<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/LOGO-sensor%20Ver1.3.png" alt="Image du LOGO-sensor Ver1.3"/>

• Nous avons cherché des projets qui faisait individuellement ce que nous voulons faire et on est tombé sur plusieurs sites et vidéos YouTube (comme <a href="https://www.youtube.com/watch?v=bn3KiEK4wJ0">celle-ci</a>, qui va vraisemblablement bien nous aider pour le <em>thermomètre de l'air ambiant</em> en Arduino).

<hr>

<h2>• Rapport de la séance 2 du Lundi 17 Décembre 2018 :</h2>

• Tout d'abord, j'ai commencé par remarquer qu'il manquait une soudure dans le <strong>LOGO-sensor Ver1.3</strong>. J'ai alors tenté de souder la patte qui ne l'était pas. Pour autant, le programme, que j'ai modifié en ajoutant des commentaires ne semble toujours pas faire ce que l'ont veut, c'est-à-dire détecter la présence d'un aimant. Le montage de ce module est montré ci-dessous :
<br>
<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/LOGO-sensor%20Ver1.3%20-%20Montage.png" alt="Montage du LOGO-sensor Ver1.3">

• J'ai également récupéré le <strong>Pulse sensor</strong> :
<br>
<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Pulse%20sensor.png" alt="Image du Pulse sensor"/>
<br>
Après quelques recherches, je suis tombé sur <a href="https://letmeknow.fr/blog/2016/09/22/tuto-mise-en-place-du-capteur-pulse-sensor/">ce site</a>.
Cependant, ce qui nous est founi ne semble pas être assez complet, puisqu'il ne renvoie pas ce que nous souhaitons pour notre projet. En effet, après avoir fait quelqus tests avec le code du précédent site internet, on note que quelque chose s'affiche sur le <em>moniteur série</em> uniquement lorsque l'on tapote sur le <strong>Pulse sensor</strong>. Un tel comportement signifie donc que nous sommes morts (?), ou tout du moins jusqu'à que nous tapotons sur ledit <strong>Pulse sensor</strong>.
Ainsi, j'ai donc continué mes recherches, et je suis finalement tombé sur <a href="https://www.generationrobots.com/media/DetecteurDePoulsAmplifie/PulseSensorAmpedGettingStartedGuide.pdf">ce site</a>. Mon camarade <strong>Damien</strong> a alors essayé de faire fonctionner le programme en le modifiant (cf : <a href="https://github.com/PolyTool/PolyTool/blob/master/Rapports%20des%20seances/LENORMAND%20Damien.md#--s%C3%A9ance-du-17-d%C3%A9cembre-">son compte-rendu<a>).
J'ai également trouvé un <a href="https://pulsesensor.com/">site</a> qui s'apparente à être le site officiel du <strong>Pulse sensor</strong>. Je me suis alors documenté sur les différentes étapes à effectuer pour faire un <strong>Pulse sensor</strong> cohérent avec notre projet : j'ai installé les différentes parties adhésives (pour qu'à l'avenir les mesures soient moins faussées et pour une certaine longévité du module) et j'ai trouvé la librairie <em>PulseSensor</em>, que j'ai alors installé dans mon logiciel <em>Arduino</em>. Cela va nous permettre  de communiquer correctement avec ce nouveau module, par le bias du logiciel <em>Arduino</em> et de la carte du même nom.
    
• Après avoir fait quelques tests plutôt convainquants pour le module <strong>Pulse sensor</strong>, je suis retourné sur le module <strong>LOGO-sensor Ver1.3</strong>. Après avoir soudé correctement (comme annoncé plus haut) la patte qui ne l'était pas (comme <a href="https://github.com/PolyTool/PolyTool/blob/master/Ressources/LOGO-sensor%20Ver1.3%20soudé.png">ceci</a>), nous avons essayé de nouveau de faire fonctionner le module. Rien de convaincant encore une fois. J'ai d'ailleurs mis à jour le <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/LOGO-sensor%20Ver1.3%20(2.0).ino">programme associé</a>, en ajoutant des commentaires et des <em>print</em> pour savoir où on en est dans le programme.

<hr>

<h2>• Pendant les vacances de Noël :</h2>

• J'ai apporté quelques informations supplémentaires suite au mail de <strong>Pascal Masson</strong>.

• J'ai mis en ligne le <strong>Diagramme de Gantt</strong> du projet. Il est disponible <a href="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Diagramme%20de%20Gantt.png">ici</a> (ou <a href="https://raw.githubusercontent.com/PolyTool/PolyTool/master/Ressources/Diagramme%20de%20Gantt.png">ici</a> pour le voir en plus grand), ainsi que dans le rubrique <strong>Délais de réalisation</strong> du <a href="https://github.com/PolyTool/PolyTool/blob/master/Cahier%20des%20charges.md">Cahier des charges</a>.

<hr>

<h2>• Rapport de la séance 3 du Lundi 7 Janvier 2019 :</h2>

• À la fin de la <a href="https://github.com/PolyTool/PolyTool/blob/master/Rapports%20des%20seances/RAKOTOMALALA%20Lucas.md#-rapport-de-la-s%C3%A9ance-du-lundi-17-d%C3%A9cembre-2018-">séance du lundi 17 décembre 2018</a>, j'ai réussi à faire fonctionner correctement le module <strong>Pulse sensor</strong>. Ainsi, j'ai donc commencé à ajouter au programme la possibilité d'envoyer les résultats anciennement envoyés au <em>moniteur série</em> directement sur le téléphone, grâce à l'application <strong>Bluetooth Electronics</strong>, et la fonctionnalité <em>Text</em> de cette application.
<br>
J'ai donc fait <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/Pulse%20sensor%20(Bluetooth).ino">ce programme</a>. Il marche correctement, et voici le montage :
<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Pulse%20sensor%20avec%20Bluetooth%20-%20Montage.png" alt="Montage du Pulse sensor avec le module Bluetooth"/>
<br>
Cependant, lors des tests, je me suis rendu compte qu'il persisté toujours un problème avec le <strong>Pulse sensor</strong> : les mesures restent assez aléatoires dans le sens où le <strong>Pulse sensor</strong> ne détecte pas toujours un battement, même après avoir baissé le seuil de tolérance (cf : les <em>lignes 6 et 7</em> de ce <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/Pulse%20sensor.ino">programme</a>).

• Par la suite, je me suis encore posé sur le problème du <strong>Pulse sensor</strong>. Même en ayant baissé le seuil de tolérance, il ne semble pas comprendre qu'il y a un battement. En le positionnant au niveau du cou, on a un résultat satisfaisant mais cela ne répond pas à la problématique de notre projet, puisque nous voulons un outil accessible. Il faudrait que nous puissions le mettre sur le poignet, à défaut détecter quoi que ce soit sur l'index gauche ou droit. Je réfléchis encore à une relation durable pour résoudre le problème.

• J'ai par ailleurs aider à faire fonctionner le <strong>capteur à effet Hall</strong> avec Damien.

<hr>

<h2>• Rapport de la séance 4 du Lundi 14 Janvier 2019 :</h2>

• J'ai récupéré 3 modules aujourd'hui : la <strong>photorésistance</strong>, le <strong>capteur de température ambiante</strong> ainsi que le <strong>capteur de température corporelle</strong>.

• J'ai commencé à écrire un programme pour la <strong>photorésistance</strong>, et j'ai obtenu <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/Photoresistance.ino">ceci</a>. Le programme fonctionne et fait ce que je veux, c'est-à-dire envoyer un message en fonction de la luminosité ambiante. Pour ce programme, vous trouverez le montage associé <a href="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Photoresistance%20-%20Montage.png">ici</a>.

• J'ai ensuite ajouté le module <em>Bluetooth</em> au montage de la <strong>photorésistance</strong>, montage que vous retrouverez <a href="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Photoresistance%20avec%20Bluetooth%20-%20Montage.png">ici</a>. J'ai adapté le programme suivant pour y ajouter ce nouveau module. Voici ce que j'ai écrit : <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/Photoresistance%20(Bluetooth).ino">Photoresistance (Bluetooth).ino</a>.
J'ai par ailleurs ajouter une fonction de <em>buzzer</em> (de son) pour avertir l'utilisateur lorsque la condition 2 du programme est vérifiée (second <em>if</em>), afin que ce dernier n'ait pas besoin de regarder son smartphone durant son trajet.

• J'ai mis en relation les différents programmes compatibles avec le <em>Bluetooth</em> pour l'oral d'aujourd'hui. Il est disponible <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/Test%20du%2014%20Janvier.ino">ici</a>. Ce programme utilise 2 modules : le <strong>Pulse sensor</strong> et la <strong>photorésistance</strong>.

<hr>

<h2>• Rapport de la séance 5 du Lundi 4 Février 2019 :</h2>

• J'ai cherché des informations concernant le <strong>capteur de température PIR</strong>, cependant rien de concluant n'a pu être trouvé. En effet, celui que nous possédons avec Damien possède <em>4 pins</em> et ne ressemble en rien à ceux trouvés sur Internet. Donc au risque de griller ce petit module contenant un picot, je n'ai rien touché, et j'attends de recevoir le nouveau module commandé.

• Un problème persiste quant au <em>capteur à effet Hall</em>. Le nombre de tour continue de défiler alors que je passe une unique fois l'aimant devant. Cependant, en ajoutant un délai dans le compteur, on arrive à réduire le nombre de tour à chaque fois que l'on entre dans le compteur : le module compte dorénavant 2 tours à chaque changement d'état, malgré le réglage de l'interruption à <em>RISING</em>, c'est-à-dire uniquement lorsque l'état passe de <strong>LOW</strong> à <strong>HIGH</strong>.

• J'ai réussi à faire en sorte que les tours ne s'incrémentent que de 1 à chauqe passage de l'aimant, en modifiant légèrement le code. J'ai également corriger la distance pour qu'elle s'incrémente correctement. Il ne reste plus qu'à trouver un moyen de calculer la <em>vitesse instantanée</em>. Le montage du module reste le même qu'aux séances précédentes. Le programme a été mis à jour et est disponible <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/LOGO-sensor%20avec%20interrruption%20(2.0).ino">ici</a>.

<hr>

<h2>• Rapport de la séance 6 du Lundi 11 Février 2019 :</h2>

• Je vais, pendant la séance, chercher des modèles 3D (quitte à les modifier), pour accueillir notre projet. J'ai trouvé un modèle 3D intéressant <a href="https://cults3d.com/fr/mod%C3%A8le-3d/outil/arduino-box-boite-arduino">ici</a>, mais il ne semble pas être adapté à notre carte Arduino et ce qui est branché. Je vais donc faire le pièce chez moi pour éviter d'empiéter du temps dans la séance.

• J'ai récupéré le module <strong>LM335Z</strong>, qui va nous permettre de capter la température corporelle du l'utilisateur. J'ai modifié un programme trouvé sur Internet pour notre module. Je suis arrivé au programme suivant : <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/LM335Z.ino">LM335Z.ino</a>. Le montage est le suivant : <img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Module%20LM335Z%20-%20Montage.png" alt="Montage du module LM335Z"/>
Cependant, le programme n'affiche pas les valeurs attendues. Ceci est dû à une résistance trop petite. En effet, j'utilise une résistance de 330 Ohms, alors que la résistance conseillée est de 2000 Ohms. L'intensité du courant est donc trop grande, ce qui a pour effet d'avoir une tension constante à 5V, empêchant alors des mesures correctes.

<hr>

<h2>• Pendant les vacances du 18 Février 2019 (Hiver) :</h2>

• J'ai tenté de faire un modèle 3D pour accueillir notre projet en vain. En effet, nous n'avions pas encore une forme finale de ce que nous souhaitons proposer. Je me suis tout de même renseigné pour faire un modèle 3D propre, compatible avec une imprimante 3D.

<hr>

<h2>• Rapport de la séance 7 du Lundi 25 Février 2019 :</h2>

• Tout d'abord, j'ai essayé de faire fonctionner le module <strong>LM335Z</strong>, sans succèes, malgré de nombreuses recherches sur des forums (anglais et celui d'Arduino français). J'ai également regardé le <em>datasheet</em> du module, qui est disponible <a href="http://www.datasheetcatalog.net/datasheets_pdf/L/M/3/3/LM335Z.shtml">ici</a>. Je n'ai tout de même pas réussi à avoir une température correcte. J'ai alors donné le relais à mon camarade <strong>Damien</strong> pour qu'il tente à son tour de faire fonctionner ce module.

• J'ai également fait le programme qui réunit tous les modules qui fonctionnent à la rédaction de ce rapport (c'est-à-dire le jour même). Il est disponible <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/Modules%20r%C3%A9unis%20(Bluetooth).ino">ici</a>. Des commentaires ont été ajouté (par <em>Damien</em> et moi) pour une meilleure compréhension du programme disponible plus haut. En effet, étant assez long, on a essayé de clarifier ledit programme. Mon camarade <strong>Damien</strong> s'est chargé du montage sur l'ancienne carte.

• Monsieur Pascal Masson nous a également distribué une nouvelle carte Arduino qui accueillera notre projet final. J'ai alors refait le montage entier avec l'aide de <em>Damien</em> sur la nouvelle carte. Le montage est disponible <a href="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Modules%20r%C3%A9unis%20-%20Montage%20sur%20Arduino%20Uno%20R3.png">ici</a> et visible ci-dessous :
<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Modules%20r%C3%A9unis%20-%20Montage%20sur%20Arduino%20Uno%20R3.png" alt="Montage de tous les modules réunis fonctionnels sur la nouvelle carte Arduino Uno R3"/>

<hr>

<h2>• Rapport de la séance 8 du Lundi 4 Mars 2019 :</h2>

• À défaut d'avoir un nouveau module pour le <em>capteur de pouls</em>, nous avons réfléchi quant à une boîte pour accueillir notre projet. Un dessin a été réalisé par <strong>Damien</strong>. Nous avons fini par dire que le meilleur choix est de faire une boîte avec des planches découpées. Nous irons au <em>FabLab</em> ce <strong>Jeudi 7 Mars 2019</strong> pour faire ladite boîte puisqu'aujourd'hui le <em>FabLab</em> n'est pas ouvert. Nous avons utilisé <a href="http://carrefour-numerique.cite-sciences.fr/fablab/wiki/doku.php?id=machines:decoupe_laser:trucs_astuces:generateur_boite_encoches">ce site</a> pour générer le fichier pour la découpe de la boîte, et nous avons alors le <a href="https://github.com/Furbor/PolyTool/blob/master/Ressources/Bo%C3%AEte%20sans%20modification%20de%20PolyTool.svg">fichier suivant</a>. Les caractéristiques de la boîte sont les suivantes : profondeur : 81mm, hauteur : 71mm, largeur : 91mm, largeur des encoches : 15mm, épaisseur du matériau : 5mm.

• J'ai commencé à écrire le rapport final du projet.

• Un nouveau module nous a été distribué par Monsieur Pascal Masson. Ce module s'appelle le <strong>HW-691</strong> et permet d'évaluer la température de l'entité la plus proche du capteur. De base, nous aurions voulu utilisé ce module pour avoir la température de l'utilisateur. Cependant, nous ne souhaitons pas faire un long cable comme celui du <strong>Pulse sensor</strong> pour cela. Ainsi, nous pouvons utilisé ce module pour avoir la température de la carte pour vérifier la température de l'ensemble.

<hr>

<h2>• Rapport de la session au <em>FabLab</em> du Jeudi 7 Mars 2019 :</h2>

<strong>But :</strong> Découper la planche de bois que nous avons préparé lors de la <a href="https://github.com/Furbor/PolyTool/blob/master/Rapports%20des%20seances/RAKOTOMALALA%20Lucas.md#-rapport-de-la-s%C3%A9ance-8-du-lundi-4-mars-2019-">séance 8</a> et assembler les différentes pièces.
<hr>
<br>
• J'ai installé <em><a href="https://inkscape.org/fr/">Inkscape</a></em> pour modifier le fichier que nous avons généré lors de la séance précédente. J'ai alors obtenu le fichier qui est disponible <a href="https://github.com/Furbor/PolyTool/blob/master/Ressources/Bo%C3%AEte%20finale%20de%20PolyTool.svg">ici</a>. J'ai ajouté des trous pour correspondre aux dessins de mon camarade <strong>Damien</strong> (dessins réalisés lors de la précédente séance également, et disponible sur <a href="https://github.com/Furbor/PolyTool/blob/master/Rapports%20des%20seances/LENORMAND%20Damien.md#--s%C3%A9ance-du-4-mars-">son compte-rendu</a>).
