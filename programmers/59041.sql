-- 코드를 입력하세요
SELECT name, count(name) as count from animal_ins group by name having count >= 2 order by name;