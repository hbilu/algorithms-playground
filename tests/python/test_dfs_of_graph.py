import sys
import os
import pytest
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../../python_playground')))

from search.dfs_of_graph import DFS

@pytest.fixture
def graphDFS():
    return DFS()


def test_example_1(graphDFS):
    adj = [[2, 3, 1], [0], [0, 4], [0], [2]]
    expected = [0, 2, 4, 3, 1]
    assert graphDFS.dfs(adj) == expected

def test_example_2(graphDFS):
    adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]  # more complex graph
    expected = [0, 1, 2, 3, 4]
    assert graphDFS.dfs(adj) == expected

def test_single_node(graphDFS):
    adj = [[]]
    expected = [0]
    assert graphDFS.dfs(adj) == expected

def test_linear_graph(graphDFS):
    adj = [[1], [2], [3], []]
    expected = [0, 1, 2, 3]
    assert graphDFS.dfs(adj) == expected

def test_cyclic_graph(graphDFS):
    adj = [[1], [2], [0]]
    expected = [0, 1, 2]
    assert graphDFS.dfs(adj) == expected

def test_fully_connected(graphDFS):
    adj = [[1, 2], [0, 2], [0, 1]]
    expected = [0, 1, 2]
    assert graphDFS.dfs(adj) == expected