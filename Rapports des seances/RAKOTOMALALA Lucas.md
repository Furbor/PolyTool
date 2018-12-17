<h1>Ici, j'écrirais tous mes rapports de séances.</h1>

<hr>
    
<h2>• Rapport de la séance du Lundi 10 Décembre 2018 :</h2>

• Nous avons commencé par la création du GitHub pour le projet Arduino.

• Après avoir regardé les différents sites et nos besoins, j'ai conclu que le coût projet s'élèverait au maximum à 50€. Un prix plus juste est développé dans le <strong><a href="https://github.com/PolyTool/PolyTool/blob/master/Cahier%20des%20charges.md">cahier des charges</a></strong>.

• Nous avons également réfléchi quant à la répartition des tâches pour les différents modules et j'ai commencé à réaliser le <strong>diagramme de Gantt</strong>. J'essaierai de le finaliser avant la prochaine séance, c'est-à-dire avant le <strong>lundi 17 décembre 2018</strong>.

• J'ai commencé à écrire le <strong>cahier des charges</strong> afin que nous ayons une idée plus précise des choses à faire.

• Nous nous sommes ensuite renseignés quant aux différents modules à utiliser. Je me suis occupé de trouver quelques modules, comme le <em><a href="https://www.amazon.fr/Capteur-pouls-capteur-cardiaque-Arduino/dp/B01DKET4LS">capteur de pouls<a></em>.

• Pour le <em>compteur kilométrique</em> et le <em>compteur de vitesse</em>, je pense que nous avons besoin d'un unique module, qui fera les deux options en même temps en travaillant sur le code Arduino directement. Après avoir demandé de explications à M. Pascal Masson sur le fonctionnement de l'<strong>effet Hall</strong>, il m'a donné un module permettant de faire le <em>compteur kilométrique</em> (et je l'espère le <em>compteur de vitesse</em>, par le biais de ce module. Les informations concernant ce module se trouve <a href="http://lien-du-TD4-d-elec3-de-pmasson">ici</a>. De ce que j'ai retenu, il faudra détecter un changement de tension, lors du passage de l'aimant devant le module <strong>LOGO-sensor Ver1.3</strong>.

• J'ai alors testé le module <strong>LOGO-sensor Ver1.3</strong>, dont le code est disponible <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/LOGO-sensor%20Ver1.3.ino">ici</a>, mais un problème persiste. Il ne semble pas faire le distintion entre la présence d'aimant ou non.
<br>
<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/LOGO-sensor%20Ver1.3.png" alt="Image du LOGO-sensor Ver1.3">

• Nous avons cherché des projets qui faisait individuellement ce que nous voulons faire et on est tombé sur plusieurs sites et vidéos YouTube (comme <a href="https://www.youtube.com/watch?v=bn3KiEK4wJ0">celle-ci</a>, qui va vraisemblablement bien nous aider pour le <em>thermomètre de l'air ambiant</em> en Arduino).

<hr>

<h2>• Rapport de la séance du Lundi 17 Décembre 2018 :</h2>

• Tout d'abord, j'ai commencé par remarquer qu'il manquait une soudure dans le <strong>LOGO-sensor Ver1.3</strong>. J'ai alors tenté de souder la patte qui ne l'était pas. Pour autant, le programme, que j'ai modifié en ajoutant des commentaires ne semble toujours pas faire ce que l'ont veut, c'est-à-dire détecter la présence d'un aimant. Le montage de ce module est montré ci-dessous :
<br><img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/LOGO-sensor%20Ver1.3%20-%20Montage.png" alt="Montage du LOGO-sensor Ver1.3">

• J'ai également récupéré le <strong>Pulse sensor</strong> :
<br>
<img src="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Pulse%20sensor.png" alt="Image du Pulse sensor">
Après quelques recherches, je suis tombé sur <a href="https://letmeknow.fr/blog/2016/09/22/tuto-mise-en-place-du-capteur-pulse-sensor/">ce site</a>.
<br>
Cependant, il ne semble pas être assez complet, puisqu'il ne renvoie pas ce que nous souhaitons pour notre projet.
<br>Ainsi, après quelques recherches, je suis tombé sur <a href="https://www.generationrobots.com/media/DetecteurDePoulsAmplifie/PulseSensorAmpedGettingStartedGuide.pdf">ce site</a>. Mon camarade <strong>Damien</strong> a alors essayé de faire fonctionner le programme en le modifiant (cf : <a href="https://github.com/PolyTool/PolyTool/edit/master/Rapports%20des%20seances/LENORMAND%20Damien.md">son compte-rendu<a>).
<br>J'ai également trouvé un <a href="https://pulsesensor.com/">site</a> qui s'apparente à être le site officiel du <strong>Pulse sensor</strong>. Je me suis alors documenté sur les différentes étapes à effectuer pour faire un <strong>Pulse sensor</strong> cohérent avec notre projet. En suivant le site, j'ai trouvé la librairie <em>PulseSensor</em> et je l'ai installé dans mon logiciel <em>Arduino</em>.
    
 • Après avoir fait quelques tests plutôt convainquants pour le module <strong>Pulse sensor</strong>, je suis retourné sur le module <strong>LOGO-sensor Ver1.3</strong>. Après avoir soudé correctement (comme annoncé plus haut) la patte qui ne l'était pas (comme <a href="https://github.com/PolyTool/PolyTool/blob/master/Ressources/LOGO-sensor%20Ver1.3%20soudé.png">ceci</a>), nous avons essayé de nouveau de faire fonctionner le module. Rien de convaincant encore une fois. J'ai d'ailleurs mis à jour le <a href="">programme associé</a>, en ajoutant des commentaires et des <em>print</em> pour savoir où on en est dans le programme.
