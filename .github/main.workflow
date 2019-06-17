workflow "cibuild on push" {
  on = "push"
  resolves = ["GitHub Action for Docker"]
}

action "build container" {
  uses = "actions/docker/cli@8cdf801b322af5f369e00d85e9cf3a7122f49108"
  args = ["build", "-t", "parkr-stuff", "."]
}

action "script/cibuild" {
  uses = "actions/docker/cli@8cdf801b322af5f369e00d85e9cf3a7122f49108"
  needs = ["build container"]
  args = ["run", "parkr-stuff", "script/cibuild"]
}
