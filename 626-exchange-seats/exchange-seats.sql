SELECT
  CASE
    WHEN id%2=1 AND id+1 IN (SELECT id FROM SEAT) then id+1 -- odd seat & if next seat exists in table, so swap id n id+1
    WHEN id%2=0 THEN id-1 -- id is even, swap w id-1
    ELSE id -- last id
    END AS id,student
FROM Seat
ORDER BY id;
    