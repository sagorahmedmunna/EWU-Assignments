--trigger for updating team points
CREATE OR REPLACE TRIGGER update_team_points_trigger
AFTER INSERT ON iccresult
FOR EACH ROW
BEGIN
UPDATE team
SET points = points + :NEW.points1
WHERE team_id = :NEW.team1;

UPDATE team
SET points = points + :NEW.points2
WHERE team_id = :NEW.team2;

COMMIT;
END;
/

--trigger for updating player stat
CREATE OR REPLACE TRIGGER update_player_stats_trigger
AFTER INSERT ON player_stat
FOR EACH ROW
BEGIN
UPDATE player
SET run_scored = run_scored + :NEW.s_run_scored
WHERE player_id = :NEW.s_player_id;

UPDATE player
SET wicket_taken = wicket_taken + :NEW.s_wicket_taken
WHERE player_id = :NEW.s_player_id;

UPDATE player
SET catches = catches + :NEW.s_catches
WHERE player_id = :NEW.s_player_id;

END;
/
