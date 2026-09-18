-- Write your PostgreSQL query statement below
select Product.product_name, Sales.year, Sales.price
from Product 
join Sales
on sales.product_id= Product.product_id;