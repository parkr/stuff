workflow "cibuild on push" {
  on = "push"
  resolves = ["script/cibuild-stuff-docker"]
}

action "script/cibuild-stuff-docker" {
  uses = "actions/docker/cli@8cdf801b322af5f369e00d85e9cf3a7122f49108"
  args = ["script/cibuild-stuff-docker"]
}
