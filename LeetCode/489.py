class Solution:
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        root = (1, 3)
        visited = set()
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]
        j = 0
        def turn_180(robot):
            robot.turnRight()
            robot.turnRight()
            
        def undo(robot):
            turn_180(robot)
            robot.move()
            turn_180(robot)
        
        def DFS(current):
            nonlocal visited, j
            robot.clean()
            visited.add(current)
            for i in range(4):
                neighbor = (current[0] + dr[j], current[1] + dc[j])
                if neighbor not in visited:
                    if robot.move():
                        visited.add(neighbor)
                        DFS(neighbor)
                        undo(robot)
                j = (j + 1) % 4
                robot.turnRight()
        DFS(root)