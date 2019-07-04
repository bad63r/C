# Documentation
Ime projekta: licni asistent

Mikrokontroler: particle(photon)

Projekat je zamisljen tako da se kreira neka vrsta licnog asistenta i da
se pomocu njega kontrolisu uredjaji u vasoj okolini. Za tu svrhu
koriscen je particle mikrokontroler(www.particle.io) koji se preko wi-fi
programira i upravlja. Particle ima neku svoju modifikovanu verziju C-a
u kome se programira.  On ima mogucnost da se poveze i na mobilni i na
internet( IoT). To se postize uz pomoc particle aplikacije za android.
Posto on nema u sebi sofver koji bi to odradio uz pomoc te aplikacije ga
navodimo na koju bi smo mrezu hteli da se kontektuje. Kada se poveze,
aplikacija nije vise toliko bitna iako ima dosta korisnih mogucnosti.
Bitno je naglasiti da bi mreze trebala da ima sve portove otvorene i da
ne bude proxy jer inace nece raditi jer nije u saglasnosti sa
podesavanjima mikrokotrolera. Tako konektovan na internet, moguce ga je
kontrolisati preko web stranice. U projektu su koriscena crvena,zelena i
plava dioda kao i buzer i IR senzor pokreta. U kodu takodje postoji i
deo programiran za relej ali nisam mogao da nadjem sijalicu od 9 V. Kada
je u pitanju senzor on salje povratnu informaciju koju smesta u bazu
podataka i koju je moguce prikazati na web stranici kada je detektovano/
nije detektovano kretanje. Web sajt uzima podatke iz paze podataka preko
gotovih api-a koju su kreirani od strane particle tima gde se za to i
koriste posebne funkcije u kodu mikrokontrolera Particle.variable().
Svaki put kada kliknem na sajt informacija se salje do njihovih servera
u Americi i nazad. Kliktanjem na dugmice na web sajtu se salje neka
informacija ka mikrokontroleru gde se dodelju razlicite vrednosti u
zavisnoti koje smo dugme pritisli i koje se kasnije proveravaju u kodu
kako bi smo dobili zeljenu funkcionalnost.

Web stranicu sam pisao u html-u kao i deo u php-u i javascript-u koji
obradjuju podatke u pozadini.. Html cini kostur sajta, dok su php i
javascript koriceni da bi se obradila baza podataka. Da bi sajt uopste
radio morao sam da instaliram php server . Posto koristim Linux to sam
uradio kao "sudo pacman -S php" . Nakon toga sam kreirao server u lokalu
"php -S localhost:8000" gde sam tu "adresu" upisao u Firefox i dobio
zeljenu web stranicu koju sam kreirao. Daljim kliktanjem na dugmice imam
mogucnost da palim ili gasim zeljene uredjaje(ovo sto sam ja pravio je
bila neka vrsta makete) kao i da vidim stanje senzora povezanog na
mikrokontroler preko interneta. Glavni problem koji nisam uspeo da
resim(jos uvek, jer mi je isticalo vreme za projekat ali planiram sam da
ga resim u skorije vreme) je problem u komunikaciji kada kliknem na neko
dugme na sajtu on mi vrati povratni dzejson koji nisam znao kako da
obradim u javascriptu kako bi me vration na pocetnu adresu mog web
sajta. Pa sam dr umesto toga sluzio obicnom strelicom u nazad na Firefox-u.

Tomislav Pap ee139/2013
