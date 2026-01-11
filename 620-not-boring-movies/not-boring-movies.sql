SELECT c.id, c.movie,c.description,c.rating FROM Cinema c
WHERE c.id%2 =1 and c.description != 'boring'
ORDER BY rating DESC; 
