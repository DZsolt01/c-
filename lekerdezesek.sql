--1.Minden információ lekérdezése, teljes áttekintés.
SELECT *
FROM C##Evnat.grades2015;

--2.A kovásznai megyei diákok neve(kódjai)
SELECT name
FROM C##Evnat.grades2015
WHERE Location LIKE 'Kovaszna';

--3.A kovaszna megyei diakok atlaga, es a tantargyakbol elert jegyek szama
SELECT name, avg, romanian, MATHEMATICS, NATIVELANG
FROM C##Evnat.GRADES2015
WHERE Location LIKE 'Kovaszna' and avg >= 5;

--4.A kovaszna megyei magyar diakok roman jegyei
Select name, ROMANIAN
FROM C##Evnat.GRADES2015
WHERE Location = 'Kovaszna' and NATIONALITY = 'Maghiara';

--5.A 9es atlag feletti diakok szama, novekevo sorrendbe
Select name as "Name", avg as "AVG"
FROM C##Evnat.GRADES2015
WHERE avg > 9
ORDER BY avg ASC;

--6.A Korosi Csoma Sandor liceum diakjainak jegyei
Select name, schoolname, ROMANIAN, MATHEMATICS, NATIVELANG
FROM C##Evnat.GRADES2015
WHERE SCHOOLNAME like 'Korosi Csoma Sandor Liceum';

--7.Azok a diakok neve, iskolaja,megyeje,  amelyek 10es atlaggal vegeztek
SELECT name, schoolname, county as COUNTRY
FROM C##Evnat.GRADES2015
where avg = 10;

--8.A diakok teljes letszama, valamint kulon bontva varosra/falura.
SELECT COUNT(name) AS "Total Students",
SUM(DECODE(medium, 'Rural', 1, 0)) AS "Number of Students Rural",
SUM(DECODE(medium, 'Urban', 1, 0)) AS "Number of Students Urban"
FROM C##EVNAT.GRADES2015;

--9.Azok a magyar diakok akik romanbol 9.5 felett irtak
Select name, schoolname, ROMANIAN
FROM C##Evnat.GRADES2015
where NATIONALITY = 'Maghiara' and ROMANIAN > 9.5;

--10. Iskolak szerinti beosztas, novekvo sorrendben, legjobb elert eredmeny
SELECT schoolname AS "School", MAX(avg) AS "Max Average"
FROM C##EVNAT.GRADES2015
GROUP BY schoolname
ORDER BY "Max Average" ASC;