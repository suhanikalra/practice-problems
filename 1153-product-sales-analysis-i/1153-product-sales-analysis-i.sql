SELECT s.year, s.price, p.product_name
FROM Sales s
LEFT JOIN Product p
 ON s.product_id = p.product_id;
