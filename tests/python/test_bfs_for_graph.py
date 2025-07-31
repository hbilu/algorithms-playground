import sys
import os
import pytest
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../../python_playground')))

from search.bfs_for_graph import BFS

@pytest.fixture
def graphBFS():
    return BFS()

def test_bfs_example_1(graphBFS):
    adj = [[1], [0, 2], [1, 3], [2]]
    assert graphBFS.bfs(adj) == [0, 1, 2, 3]

def test_bfs_example_2(graphBFS):
    adj = [[1, 2], [0, 2, 3], [0, 1, 4], [1, 4], [2, 3]]
    assert graphBFS.bfs(adj) == [0, 1, 2, 3, 4]

def test_bfs_single_node(graphBFS):
    adj = [[]]
    assert graphBFS.bfs(adj) == [0]

def test_bfs_two_nodes(graphBFS):
    adj = [[1], [0]]
    assert graphBFS.bfs(adj) == [0, 1]

def test_bfs_star_topology(graphBFS):
    #    0
    #  / | \
    # 1  2  3
    adj = [[1, 2, 3], [0], [0], [0]]
    assert graphBFS.bfs(adj) == [0, 1, 2, 3]

def test_bfs_cycle(graphBFS):
    adj = [[1, 3], [0, 2], [1, 3], [2, 0]]
    assert graphBFS.bfs(adj) == [0, 1, 3, 2]

def test_bfs_fully_connected(graphBFS):
    adj = [[1, 2], [0, 2], [0, 1]]
    assert graphBFS.bfs(adj) == [0, 1, 2]

def test_bfs_prefers_shortest_path_first(graphBFS):
    # 0 → 1 → 3
    #  \      ↑
    #   → 2 →
    adj = [[1, 2], [3], [3], []]
    assert graphBFS.bfs(adj) == [0, 1, 2, 3]