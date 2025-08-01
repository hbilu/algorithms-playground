import sys
import os
import pytest
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../../python_playground')))

from search.iterative_deepening_search_IDS import IDS

@pytest.fixture
def ids():
    return IDS()

@pytest.fixture
def sample_graph():
    return {
        'A': ['B', 'C'],
        'B': ['D', 'E'],
        'C': ['F'],
        'D': [],
        'E': ['G'],
        'F': [],
        'G': []
    }

#          A        ← depth 0
#        /   \
#       B     C     ← depth 1
#      / \     \
#     D   E     F   ← depth 2
#          \
#           G       ← depth 3

def test_target_exists(sample_graph, ids):
    assert ids.iterative_deepening_search(sample_graph, 'A', 'G', max_depth=5) is True

def test_target_does_not_exist(sample_graph, ids):
    assert ids.iterative_deepening_search(sample_graph, 'A', 'Z', max_depth=5) is False

def test_root_is_target(sample_graph, ids):
    assert ids.iterative_deepening_search(sample_graph, 'A', 'A', max_depth=5) is True

def test_target_at_max_depth(sample_graph, ids):
    assert ids.iterative_deepening_search(sample_graph, 'A', 'G', max_depth=2) is False
    assert ids.iterative_deepening_search(sample_graph, 'A', 'G', max_depth=3) is False
    assert ids.iterative_deepening_search(sample_graph, 'A', 'G', max_depth=4) is True

def test_disconnected_graph(ids):
    graph = {
        'A': ['B'],
        'B': [],
        'C': ['D'],
        'D': []
    }
    #    A  ← depth 0 →  C
    #    |               | 
    #    B  ← depth 1 →  D
    assert ids.iterative_deepening_search(graph, 'A', 'D', max_depth=5) is False
    assert ids.iterative_deepening_search(graph, 'C', 'D', max_depth=2) is True