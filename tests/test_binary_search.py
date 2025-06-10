import sys
import os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../python_playground')))

from search.binary_search import binary_search

def test_binary_search_found():
    assert binary_search([1, 3, 5, 7, 9], 5) == 2

def test_binary_search_not_found():
    assert binary_search([1, 3, 5, 7, 9], 4) == -1