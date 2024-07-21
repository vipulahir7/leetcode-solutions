WITH total_requests AS (
    SELECT 
        s.user_id,
        COUNT(c.action) AS total_count
    FROM 
        Signups s
    LEFT JOIN 
        Confirmations c ON s.user_id = c.user_id
    GROUP BY 
        s.user_id
),
confirmed_requests AS (
    SELECT 
        s.user_id,
        COUNT(CASE WHEN c.action = 'confirmed' THEN 1 END) AS confirmed_count
    FROM 
        Signups s
    LEFT JOIN 
        Confirmations c ON s.user_id = c.user_id
    GROUP BY 
        s.user_id
)
SELECT
    t.user_id,
    ROUND(
        CASE 
            WHEN t.total_count = 0 THEN 0
            ELSE c.confirmed_count / t.total_count
        END, 
        2
    ) AS confirmation_rate
FROM
    total_requests t
LEFT JOIN
    confirmed_requests c ON t.user_id = c.user_id;
