import sys
import os
import pytest
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../../python_playground')))

from search.uniform_cost_search_UCS import UCS

@pytest.fixture
def ucs():
    return UCS()

def test_basic_path(ucs):
    graph = {
        'A': [('B', 1), ('C', 5)],
        'B': [('D', 2)],
        'C': [('D', 2)],
        'D': []
    }
    path, cost = ucs.uniform_cost_search(graph, 'A', 'D')
    assert path == ['A', 'B', 'D']
    assert cost == 3

def test_no_path(ucs):
    graph = {
        'A': [('B', 1)],
        'B': [],
        'C': [('D', 2)]
    }
    path, cost = ucs.uniform_cost_search(graph, 'A', 'D')
    assert path is None
    assert cost == -1

def test_start_is_goal(ucs):
    graph = {
        'A': [('B', 1)],
        'B': [('A', 1)]
    }
    path, cost = ucs.uniform_cost_search(graph, 'A', 'A')
    assert path == ['A']
    assert cost == 0

def test_multiple_paths(ucs):
    graph = {
        'A': [('B', 2), ('C', 2)],
        'B': [('D', 2)],
        'C': [('D', 1)],
        'D': [('E', 3)],
        'E': []
    }
    path, cost = ucs.uniform_cost_search(graph, 'A', 'E')
    # Shortest-cost path: A → C → D → E (2 + 1 + 3 = 6)
    assert path == ['A', 'C', 'D', 'E']
    assert cost == 6

def test_disconnected_graph(ucs):
    graph = {
        'A': [('B', 1)],
        'B': [],
        'X': [('Y', 1)],
        'Y': []
    }
    path, cost = ucs.uniform_cost_search(graph, 'A', 'Y')
    assert path is None
    assert cost == -1

def test_cyclic_graph(ucs):
    graph = {
        'A': [('B', 1)],
        'B': [('C', 2)],
        'C': [('A', 3), ('D', 1)],
        'D': []
    }
    path, cost = ucs.uniform_cost_search(graph, 'A', 'D')
    assert path == ['A', 'B', 'C', 'D']
    assert cost == 4

def test_zero_cost_edges(ucs):
    graph = {
        'A': [('B', 0), ('C', 2)],
        'B': [('D', 0)],
        'C': [('D', 2)],
        'D': []
    }
    path, cost = ucs.uniform_cost_search(graph, 'A', 'D')
    assert path == ['A', 'B', 'D']
    assert cost == 0

def test_equal_cost_paths(ucs):
    graph = {
        'A': [('B', 2), ('C', 2)],
        'B': [('D', 2)],
        'C': [('D', 2)],
        'D': []
    }
    path, cost = ucs.uniform_cost_search(graph, 'A', 'D')
    assert path in [['A', 'B', 'D'], ['A', 'C', 'D']]
    assert cost == 4