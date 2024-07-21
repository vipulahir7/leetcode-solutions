WITH FirstLogin AS (
    SELECT
        player_id,
        MIN(event_date) AS first_login_date
    FROM
        Activity
    GROUP BY
        player_id
),
ConsecutiveLogin AS (
    SELECT
        fl.player_id
    FROM
        FirstLogin fl
    JOIN
        Activity a ON fl.player_id = a.player_id
                  AND a.event_date = DATE_ADD(fl.first_login_date, INTERVAL 1 DAY)
)
SELECT
    ROUND(COUNT(DISTINCT cl.player_id) / COUNT(DISTINCT fl.player_id), 2) AS fraction
FROM
    FirstLogin fl
LEFT JOIN
    ConsecutiveLogin cl ON fl.player_id = cl.player_id;
