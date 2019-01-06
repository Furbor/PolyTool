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
Cependant, ce qui nous est founi ne semble pas être assez complet, puisqu'il ne renvoie pas ce que nous souhaitons pour notre projet. En effet, après avoir fait quelqus tests avec le code du précédent site internet, on note que quelque chose s'affiche sur le <em>moniteur série</em> uniquement lorsque l'on tapote sur le <strong>Pulse sensor</strong>. Un tel comportement signifie donc que nous sommes morts (?), ou tout du moins jusqu'à que nous tapotons sur ledit <strong>Pulse sensor</strong>.
<br>Ainsi, j'ai donc continué mes recherches, et je suis finalement tombé sur <a href="https://www.generationrobots.com/media/DetecteurDePoulsAmplifie/PulseSensorAmpedGettingStartedGuide.pdf">ce site</a>. Mon camarade <strong>Damien</strong> a alors essayé de faire fonctionner le programme en le modifiant (cf : <a href="https://github.com/PolyTool/PolyTool/blob/master/Rapports%20des%20seances/LENORMAND%20Damien.md#--s%C3%A9ance-du-17-d%C3%A9cembre-">son compte-rendu<a>).
<br>J'ai également trouvé un <a href="https://pulsesensor.com/">site</a> qui s'apparente à être le site officiel du <strong>Pulse sensor</strong>. Je me suis alors documenté sur les différentes étapes à effectuer pour faire un <strong>Pulse sensor</strong> cohérent avec notre projet : j'ai installé les différentes parties adhésives (pour qu'à l'avenir les mesures soient moins faussées et pour une certaine longévité du module) et j'ai trouvé la librairie <em>PulseSensor</em>, que j'ai alors installé dans mon logiciel <em>Arduino</em>. Cela va nous permettre  de communiquer correctement avec ce nouveau module, par le bias du logiciel <em>Arduino</em> et de la carte du même nom.
    
 • Après avoir fait quelques tests plutôt convainquants pour le module <strong>Pulse sensor</strong>, je suis retourné sur le module <strong>LOGO-sensor Ver1.3</strong>. Après avoir soudé correctement (comme annoncé plus haut) la patte qui ne l'était pas (comme <a href="https://github.com/PolyTool/PolyTool/blob/master/Ressources/LOGO-sensor%20Ver1.3%20soudé.png">ceci</a>), nous avons essayé de nouveau de faire fonctionner le module. Rien de convaincant encore une fois. J'ai d'ailleurs mis à jour le <a href="https://github.com/PolyTool/PolyTool/blob/master/Codes%20Arduino/LOGO-sensor%20Ver1.3%20(2.0).ino">programme associé</a>, en ajoutant des commentaires et des <em>print</em> pour savoir où on en est dans le programme.

<hr>

<h2>• Pendant les vacances de Noël :</h2>
• J'ai apporté quelques informations supplémentaires suite au mail de <strong>Pascal Masson</strong>.

• J'ai mis en ligne le <strong>Diagramme de Gantt</strong> du projet. Il est disponible <a href="https://github.com/PolyTool/PolyTool/blob/master/Ressources/Diagramme%20de%20Gantt.png">ici</a> (ou <a href="https://raw.githubusercontent.com/PolyTool/PolyTool/master/Ressources/Diagramme%20de%20Gantt.png">ici</a> pour le voir en plus grand), ainsi que dans le rubrique <strong>Délais de réalisation</strong> du <a href="https://github.com/PolyTool/PolyTool/blob/master/Cahier%20des%20charges.md">Cahier des charges</a>.
