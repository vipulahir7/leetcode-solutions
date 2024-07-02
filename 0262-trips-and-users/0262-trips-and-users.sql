-- select count(status) from Trips where client_id in (select users_id from Users where banned = 'No' and role = 'client') and status='cancelled_by_driver' or status='cancelled_by_client' group by request_at

SELECT 
    request_at AS Day,
    ROUND(
        SUM(CASE 
                WHEN t.status IN ('cancelled_by_driver', 'cancelled_by_client') THEN 1 
                ELSE 0 
            END) / COUNT(*), 
        2
    ) AS "Cancellation Rate"
FROM 
    Trips t
JOIN 
    Users c ON t.client_id = c.users_id
JOIN 
    Users d ON t.driver_id = d.users_id
WHERE 
    c.banned = 'No'
    AND d.banned = 'No'
    AND t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY 
    t.request_at;
