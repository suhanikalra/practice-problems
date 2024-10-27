# Write your MySQL query statement below
select product.product_name, sales.year, sales.price from Sales
join  Product on Product.product_id = Sales.product_id;