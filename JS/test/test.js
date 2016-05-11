const chai = require('chai')
const expect = chai.expect

const G = require('../graph')

let [a, b, c, d, e, f, g] = Array(7)
      .fill()
      .map((_, i) => new G.Vertex(String.fromCharCode(65 + i)))

//directed graph
var graph = new G.Graph()

graph.addEdge(a, b)
graph.addEdge(a, c)
graph.addEdge(a, e)
graph.addEdge(b, d)
graph.addEdge(b, f)
graph.addEdge(c, g)
graph.addEdge(f, e)

describe("Testing DFS", function() {
  it('Search "E" from "A" should be TRUE', function() {
    expect(graph.dfs(a, e)).to.equal(true)
  })
  it('Search "G" from "A" should be TRUE', function() {
    expect(graph.dfs(a, g)).to.equal(true)
  })
  it('Search "E" from "B" should be TRUE', function() {
    expect(graph.dfs(b, e)).to.equal(true)
  })
  it('Search "C" from "B" should be FALSE', function() {
    expect(graph.dfs(b, c)).to.equal(false)
  })
  it('Search "D" from "C" should be FALSE', function() {
    expect(graph.dfs(c, d)).to.equal(false)
  })
  it('Search "G" from "F" should be FALSE', function() {
    expect(graph.dfs(f, g)).to.equal(false)
  })
})

describe("Testing BFS", function() {
  it('Search "E" from "A" should be TRUE', function() {
    expect(graph.bfs(a, e)).to.equal(true)
  })
  it('Search "G" from "A" should be TRUE', function() {
    expect(graph.bfs(a, g)).to.equal(true)
  })
  it('Search "E" from "B" should be TRUE', function() {
    expect(graph.bfs(b, e)).to.equal(true)
  })
  it('Search "C" from "B" should be FALSE', function() {
    expect(graph.bfs(b, c)).to.equal(false)
  })
  it('Search "D" from "C" should be FALSE', function() {
    expect(graph.bfs(c, d)).to.equal(false)
  })
  it('Search "G" from "F" should be FALSE', function() {
    expect(graph.bfs(f, g)).to.equal(false)
  })
})


  
