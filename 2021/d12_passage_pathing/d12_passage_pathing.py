from util import read_file


class UndirectedGraph:
    def __init__(self):
        self._vertices = set()
        self._edges = dict()
        self._paths = list()
        self._current_path = list()
        self._may_visit_a_small_cave_twice = False
        self._has_second_visit_in_small_cave = False
        self._double_visited_cave = list()

    def enable_visit_a_small_cave_twice(self):
        self._may_visit_a_small_cave_twice = True

    def add_edge(self, point_from, point_to):
        self._vertices.add(point_from)
        self._vertices.add(point_to)
        edges_to_from = self._edges.get(point_from, set())
        edges_to_from.add(point_to)
        self._edges[point_from] = edges_to_from
        edges_for_to = self._edges.get(point_to, set())
        edges_for_to.add(point_from)
        self._edges[point_to] = edges_for_to

    def get_number_of_paths(self, vertex):
        self._dfs(vertex)
        return len(self._paths)

    def _dfs(self, vertex: str):
        if vertex.isupper() or self._may_visit_small_cave(vertex):
            if self._may_visit_a_small_cave_twice and vertex.islower() and self._current_path.count(vertex):
                self._double_visited_cave.append(vertex)

            self._current_path.append(vertex)
            if vertex == "end":
                self._paths.append(self._current_path.copy())
            else:
                for endpoint_of_edge in self._edges.get(vertex, set()):
                    self._dfs(endpoint_of_edge)
            self._current_path.pop()
            if self._double_visited_cave.count(vertex) > 0:
                self._double_visited_cave.pop()

    def _may_visit_small_cave(self, vertex):
        limit = 0
        if self._may_visit_a_small_cave_twice and len(self._double_visited_cave) == 0 and vertex != "start":
            limit = 1
        return self._current_path.count(vertex) <= limit


def solve():
    def line_to_edge(line):
        vertices = line.split("-")
        return vertices[0].strip(), vertices[1].strip()

    lines_of_file = read_file("d12_passage_pathing/input.txt")
    edges = [line_to_edge(line_of_file) for line_of_file in lines_of_file]
    caves = UndirectedGraph()
    caves2 = UndirectedGraph()
    caves2.enable_visit_a_small_cave_twice()
    for starting_vertex, end_vertex in edges:
        caves.add_edge(starting_vertex, end_vertex)
        caves2.add_edge(starting_vertex, end_vertex)

    print("Day 12:")
    print(f"  - Part 1: {caves.get_number_of_paths('start')}")
    print(f"  - Part 2: {caves2.get_number_of_paths('start')}")
