FROM ruby:slim

WORKDIR /srv/app
COPY Gemfile.lock Gemfile.lock
RUN set -ex \
  && script/bootstrap

