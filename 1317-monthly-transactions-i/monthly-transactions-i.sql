SELECT DATE_FORMAT(trans_date,'%Y-%m')As month, country, count(*) As trans_count, Sum(state='approved')
as approved_count , Sum(amount) as trans_total_amount, sum(CASE WHEN state ='approved' THEN amount ELSE 0 END) as approved_total_amount FROM  Transactions
GROUP BY month, country
